jsonc
=====

A small, lightweight JSON colorizer for the *nix command line
Assumes the inputted JSON is valid.

Designed to be used with jsonf https://github.com/bsouther/jsonf in a pipeline.

Example:

tail -f json.log | jsonf | jsonc

This will allow you to see formatted and syntax-highlighted JSON scrolling by in your console.