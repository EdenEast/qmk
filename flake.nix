{
  description = ''
    Personal keyboard fimware
  '';

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, ... }@inputs:
    inputs.flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages."${system}";
        shell = import ./shell.nix { inherit pkgs; };
      in
      {
        devShell = shell // { buildInputs = with pkgs;[ just fd ]; };
      });
}
