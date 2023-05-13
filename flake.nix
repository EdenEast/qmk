{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        pcpp = with pkgs; python3Packages.buildPythonPackage rec {
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
          version = "0.6.0";
          format = "pyproject";

          src = pkgs.fetchFromGitHub {
            owner = "caksoylar";
            repo = "keymap-drawer";
            rev = "v${version}";
            sha256 = "sha256-NvWx6X9kfnigR2jmLo9g4neDZ3SlUr0ck3wjtPjKhWM=";
          };

          doCheck = false;

          nativeBuildInputs = with python3Packages; [
            poetry-core
          ];

          propagatedBuildInputs = with python3Packages; [
            pyyaml
            pyparsing
            pydantic
          ] ++ [ pcpp ];

        };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [ just keymap-drawer qmk ];
        };
      });
}
