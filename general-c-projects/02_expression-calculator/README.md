# Expression Calculator in C

This is a command-line calculator written in C that can parse and evaluate mathematical expressions with support for operator precedence and parentheses.

## Features

- Tokenizes infix expressions (e.g., `3 + 4 * 2`)
- Converts expressions to postfix notation (RPN)
- Evaluates the expression using a stack
- Supports:
  - Addition `+`
  - Subtraction `-`
  - Multiplication `*`
  - Division `/`
  - Parentheses `( )`
- Modular structure with headers and source files
- Compiles using a `Makefile`

## How It Works

1. **Tokenizer**: breaks down input like `3 + (4 * 2)` into tokens.
2. **Parser**: converts tokens to postfix notation using the Shunting Yard Algorithm.
3. **Evaluator**: evaluates postfix expressions using a simple stack-based approach.