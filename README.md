```md
# pipex

## About

The **pipex** project is part of the 42 curriculum, focusing on process management and inter-process communication in Unix-like systems. This project recreates the behavior of the shell's piping mechanism (`|`) using file descriptors, `pipe()`, and `dup2()` system calls, allowing one command's output to be passed as input to another.

## Features

- Emulates the shell's piping (`|`) functionality.
- Handles multiple commands and arguments.
- Redirection of input/output from/to files.
- Efficient handling of processes using `fork()`, `execve()`, and `wait()` system calls.

## Usage

1. **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/pipex.git
    cd pipex
    ```

2. **Build the project:**
    ```bash
    make
    ```

3. **Run the program:**
    ```bash
    ./pipex infile "cmd1" "cmd2" outfile
    ```

   Example:
   ```bash
   ./pipex input.txt "grep hello" "wc -l" output.txt
   ```

   This command executes `grep hello < input.txt | wc -l > output.txt`.

## Requirements

- Two mandatory files:
  - `infile`: The input file to be read by the first command.
  - `outfile`: The output file where the result will be written.

- Two or more commands in quotes (e.g., `"cmd1" "cmd2"`).

## How it Works

1. Opens `infile` for reading and `outfile` for writing.
2. Sets up a pipe to pass the output of the first command (`cmd1`) as input to the second command (`cmd2`).
3. Uses `fork()` to create child processes for each command.
4. Uses `dup2()` to redirect standard input/output for each process.
5. Executes the commands using `execve()` and waits for them to finish.

## Example

```bash
$ echo "Hello world" > infile.txt
$ ./pipex infile.txt "cat" "wc -w" outfile.txt
$ cat outfile.txt
2
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
```
