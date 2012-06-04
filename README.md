jsonc
=====

A small, lightweight JSON colorizer for the *nix command line
Assumes the inputted JSON is valid.

Designed to be used with jsonf https://github.com/bsouther/jsonf in a pipeline.

Example:

tail -f json.log | jsonf | jsonc

This will allow you to see formatted and syntax-highlighted JSON scrolling by in your console.

NOTE: You will probably always want to keep this program at the end of the pipeline and 
never redirect its output to file.
      The hidden color markup will bloat your JSON 3 to 5 fold.