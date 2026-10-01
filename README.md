# shellzinha

A Simple Bash-Inspired Shell built to learn Unix process management, file descriptors, pipes and signals.

## Features
- **REPL** GNU Readline (history, arrow keys, line editing, Ctrl-R search)
- **Persistent history** across sessions
- **Built-ins**: `cd`, `pwd`, `exit`
- **Redirection**: `<`, `>`, `>>`, `2>`
- **Pipes**: `cmd1 | cmd2 | cmd3`
- **Signal handling**: Ctrl-C kills the child, Shell stays alive
- **Interactive Programs**: `vim`, `less`, `btop`, `htop` were tested and confirmed working

## Building

Requires a POSIX system and GNU's Readline Library (generally included in most distros).

```sh
# Debian/Ubuntu
sudo apt install libreadline-dev

# Gentoo 
emerge sys-libs/readline

# Build
make
./shellzinha

```
## LICENSE
MIT
