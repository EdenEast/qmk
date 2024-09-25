{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-24.05";
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
        overlay = self': super': {
          platformdirs3 = super'.python3Packages.platformdirs.overrideAttrs (old: {
            version = "3.5.1";
            src = super'.fetchFromGitHub {
              owner = old.pname;
              repo = old.pname;
              rev = "refs/tags/3.5.1";
              hash = "sha256-/qi22jiF+P7XcG/D+dxoOrHk89amdBoGewrTqZZOsoM=";
            };
          });
        };
        pkgs = import nixpkgs { inherit system; overlays = [ overlay ]; };
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
          version = "0.18.0";
          format = "pyproject";

          src = pkgs.fetchFromGitHub {
            owner = "caksoylar";
            repo = "keymap-drawer";
            rev = "v${version}";
            sha256 = "sha256-3NLOoCSPt/2Mt+e4xL4RyAqN4gF0sAgkQoZMsmKdnYw=";
          };

          doCheck = false;

          nativeBuildInputs = with python3Packages; [
            poetry-core
          ];

          propagatedBuildInputs = with python3Packages; [
            pyyaml
            pyparsing
            pydantic
            pydantic-settings
            platformdirs3
            pcpp
          ];
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
