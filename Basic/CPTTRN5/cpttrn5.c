// CPTTRN5 - Character Patterns (Act 5)
// #basics
//
// Using two characters: . (dot) and * (asterisk) print a grid-like pattern.
// The grid will have l lines, c columns, and each square shaped element of
// the grid will have the height and width equal to s.
//
// Moreover, each of the grid elements will have a diagonal. The diagonal of
// the first square in the first line of the grid is directed towards down and
// right corner - use the \ (backslash) character to print it; while the next diagonal will be directed towards upper right corner - use the / (slash) character to print it. Print the successive diagonals alternately (please consult the example below).
//
// Input
//
// You are given t - the number of test cases and for each test case three
// positive integers: l - the number of lines, c - the number of columns in
// the grid and s - the size of the single square shaped element.
//
// Output
//
// For each of the test cases output the requested pattern (please have a
// look at the example). Use one line break in between successive patterns.
//
// Example
//
// Input:
// 3
// 3 1 2
// 4 4 1
// 2 5 2
//
// Output:
// ****
// *\.*
// *.\*
// ****
// *./*
// */.*
// ****
// *\.*
// *.\*
// ****
//
// *********
// *\*/*\*/*
// *********
// */*\*/*\*
// *********
// *\*/*\*/*
// *********
// */*\*/*\*
// *********
//
// ****************
// *\.*./*\.*./*\.*
// *.\*/.*.\*/.*.\*
// ****************
// *./*\.*./*\.*./*
// */.*.\*/.*.\*/.*
// ****************

