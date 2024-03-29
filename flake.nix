{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-23.11";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  nixConfig = {
    extra-substituters = [
      "https://edeneast-qmk-firmware.cachix.org"
    ];
    extra-trusted-public-keys = [
      "edeneast-qmk-firmware.cachix.org-1:lZ1aALkZD5qlipgrCqrJbYUAmwm6ED04fAnG23QqQaQ="
    ];
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        pcpp = with pkgs; python311Packages.buildPythonPackage rec {
          pname = "pcpp";
          version = "1.30";

          src = fetchFromGitHub {
            owner = "ned14";
            repo = "pcpp";
            rev = "v${version}";
            sha256 = "sha256-Fs+CMV4eRKcB+KdV93ncgcqaMnO5etnMY/ivmSJh3Wc=";
            fetchSubmodules = true;
          };
        };
        keymap-drawer = with pkgs; python3Packages.buildPythonApplication rec{
          pname = "keymap-drawer";
          version = "0.13.3";
          format = "pyproject";

          src = pkgs.fetchFromGitHub {
            owner = "caksoylar";
            repo = "keymap-drawer";
            rev = "v${version}";
            sha256 = "sha256-dbVpsgsWuFpmt8LMIXVTYXNSrS0gYyehULhhBtNa+Bs=";
          };

          doCheck = false;

          nativeBuildInputs = with python3Packages; [
            poetry-core
          ];

          propagatedBuildInputs = with python3Packages; [
            pyyaml
            pyparsing
            pydantic
            platformdirs
          ] ++ [ pcpp ];
        };
      in
      {
        inherit pkgs;
        devShells.default = pkgs.mkShell {
          name = "qmk";
          buildInputs = with pkgs; [
            just
            keymap-drawer
            qmk
            stow
            watchexec
          ];

          shellHook = ''
            # Prevent the avr-gcc wrapper from picking up host GCC flags
            # like -iframework, which is problematic on Darwin
            unset NIX_CFLAGS_COMPILE_FOR_TARGET
          '';
        };
      });
}
