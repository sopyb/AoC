{ pkgs ? import <nixpkgs> {} }:

with pkgs;

mkShell {
  buildInputs = [
    lolcode
  ];

  shellHook = ''
    echo "BTW LOLCODE INTEPRETR READY! :3"
    echo "USE *LULZ* 2 RUN UR CODE"
  '';
}
