# Learn Linux – My Beginner Notes

Learning Linux step by step. These are the commands I practiced while learning Linux.

## What I Need

* A Linux system
* Terminal access
* Willingness to learn and practice

## Basic Commands I Learned

| Command    | What It Does                                | Example                   |
| ---------- | ------------------------------------------- | ------------------------- |
| `pwd`      | Shows my current location                   | `pwd`                     |
| `ls`       | Lists files and folders                     | `ls`                      |
| `ls -l`    | Shows detailed file information             | `ls -l`                   |
| `cd`       | Changes to another directory                | `cd Documents`            |
| `cd ..`    | Moves to the parent directory               | `cd ..`                   |
| `cd ~`     | Goes to the Home directory                  | `cd ~`                    |
| `mkdir`    | Creates a new directory                     | `mkdir practice`          |
| `touch`    | Creates a new empty file                    | `touch notes.txt`         |
| `cat`      | Displays the contents of a file             | `cat notes.txt`           |
| `cp`       | Copies files                                | `cp notes.txt backup.txt` |
| `mv`       | Moves or renames files                      | `mv old.txt new.txt`      |
| `rm`       | Removes files                               | `rm notes.txt`            |
| `whoami`   | Displays the current username               | `whoami`                  |
| `uname -m` | Shows the system architecture               | `uname -m`                |
| `history`  | Displays previously used commands           | `history`                 |
| `cal`      | Displays the current month's calendar       | `cal`                     |
| `cal 2025` | Displays the calendar for the year 2025     | `cal 2025`                |
| `bc`       | Opens the Linux calculator for calculations | `bc -l`                   |
| `expr`     | Evaluates simple arithmetic expressions     | `expr 45 + 54`            |
| `grep`     | Searches for patterns in files              | `grep word file.txt`      |

## Running My First Script

Make the script executable:

```bash
chmod +x stupid.sh
```

This command gives execute permission to the script file.

Run the script:

```bash
./stupid.sh
```

This command executes the shell script.

## Package Commands I Used

Update package lists:

```bash
sudo apt update
```

This command downloads the latest package information from repositories.

Upgrade installed packages:

```bash
sudo apt upgrade
```

This command updates installed packages to newer versions.

Install a package:

```bash
sudo apt install package_name
```

This command installs a new package.

Remove a package completely:

```bash
sudo apt purge package_name
```

This command removes the package along with its configuration files.

Remove unnecessary packages:

```bash
sudo apt autoremove
```

This command removes unused dependencies.

## Calculator Commands

Start the calculator:

```bash
bc -l
```

Example:

```bash
45 + 65
110

x = 45
y = 67

x * y
3015

x = 3
y = 72 / x

y
24

quit
```

Simple calculations using `expr`:

```bash
expr 45 + 54
expr 45 \* 89
expr 45 '*' 99
```

## Useful Command Symbols

| Symbol | What It Does                                                | Example                 |
| ------ | ----------------------------------------------------------- | ----------------------- |
| `;`    | Runs commands one after another                             | `ls ; pwd`              |
| `&&`   | Runs the next command only if the previous command succeeds | `ls && pwd`             |
| `\|\|` | Runs the next command if the previous command fails         | `ls \|\| echo "Failed"` |
| `&`    | Runs a command in the background                            | `sleep 10 &`            |

## Finding Files

Find text files in the Home directory:

```bash
find ~ -iname "*.txt"
```

This command searches for all `.txt` files in the Home directory.

Find a specific file:

```bash
find . -name "stupid.sh"
```

This command searches for `stupid.sh` in the current directory and its subdirectories.

## Commands I Practiced

* `pwd` – Show current directory
* `ls` – List files and folders
* `ls -l` – Show detailed file information
* `cd` – Change directories
* `mkdir` – Create directories
* `touch` – Create files
* `cat` – View file contents
* `cp` – Copy files
* `mv` – Move or rename files
* `rm` – Delete files
* `find` – Search for files
* `grep` – Search for patterns in files
* `whoami` – Display current username
* `uname -m` – Show system architecture
* `history` – View command history
* `cal` – Display calendars
* `bc` – Perform calculations
* `expr` – Evaluate arithmetic expressions
* `chmod` – Change file permissions
* `sudo apt update` – Update package lists
* `sudo apt upgrade` – Upgrade installed packages
* `sudo apt install` – Install packages
* `sudo apt purge` – Remove packages completely
* `sudo apt autoremove` – Remove unused packages
* `&&`, `||`, `;`, `&` – Use command operators

## What I Learned

* How to navigate between directories
* How to create and manage files
* How to search for files
* How to search for text inside files using `grep`
* How to execute shell scripts
* How to install and remove packages
* How to use command operators
* How to view calendars in Linux
* How to perform calculations in the terminal

Still learning Linux, one command at a time! 🐧

## Just for Fun 🤍

> 💻 **"You're the `sudo` 🤍 to my heart — nothing happens without your permission."**

