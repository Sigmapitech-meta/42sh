{
  description = "42sh";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-22.11";
    cs.url = "github:Sigmanificient/coding-style-checker/user";
    cs.inputs.nixpkgs.follows = "nixpkgs";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, cs, utils } @inputs:
    utils.lib.eachDefaultSystem (system:
      with import nixpkgs { inherit system; }; {
        devShells.default = mkShell {
          packages = [
            cs.packages.${system}.report
            criterion
            gcc12
            glibc
            gcovr
            ltrace
            gnumake
            tcsh
            valgrind
          ];
        };
      });
}
