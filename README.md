# Typeless

Typeless is a command-line utility designed to simplify the process of adding aliases and functions to your shell environment. It's particularly useful for creating custom command shortcuts and complex functions in Bash, streamlining your workflow and making your terminal more efficient.

## Features

- **Create Aliases:** Quickly add new aliases to your `.bashrc`.
- **Create Functions:** Easily define new functions with multiple commands.
- **Descriptions:** Add descriptions to your aliases and functions for better recall.
- **Ease of Use:** Simple and intuitive command-line interface.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Bash shell

### Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your-username/typeless.git
   cd typeless
   gcc -o typeless typeless.c

## Run the Tool:

To use Typeless, follow these steps:

- **To add an alias:**

  ```bash
  ./typeless -a alias_name -c 'command' -d 'description'
- **To add a function with multiple commands:**

  When adding a function, you can include multiple commands. Each command should be enclosed in quotes and separated by spaces. The final argument should be the `-d` flag followed by a description of the function in quotes.

  Example:

  ```bash
  ./typeless -f myfunc 'git add .' 'git commit -m "$1"' 'git push origin main' -d 'Add, commit, and push changes to main'

