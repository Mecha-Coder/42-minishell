```text
 _  _  ____                _       _     _          _ _ 
| || ||___ \ _   _ __ ___ (_)_ __ (_)___| |__   ___| | |
| || |_ __) (_) | '_ ` _ \| | '_ \| / __| '_ \ / _ \ | |
|__   _/ __/ _  | | | | | | | | | | \__ \ | | |  __/ | |
   |_||_____(_) |_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|   
```

### **Overview**

A command-line interface (shell) that interacts with the Kernal, similar to Bash

---

### **Learnings**
- Implementing and traversing binary trees using recursion
- Designing a tokenizer and parser for shell commands

---

### **About** 

👉 [**Project requirement**](https://github.com/Mecha-Coder/42-minishell/blob/main/demo/en.subject.pdf)

A shell, also known as a CLI (Command Line Interface), is a way to interact with a computer using plain English.


![figure1](https://github.com/Mecha-Coder/42-minishell/blob/main/demo/figure1.png)


The shell waits for user input at a prompt. Once the user types a command and presses Enter, the shell parses and executes it.

Internally, the shell performs several key steps. First, it tokenizes the input string (splitting it into meaningful parts such as commands, arguments, and operators). Then, it builds an AST (Abstract Syntax Tree), which defines the execution order of commands based on operator precedence (e.g., pipes, AND, OR)

![figure2](https://github.com/Mecha-Coder/42-minishell/blob/main/demo/figure2.png)

After executing the command, the shell prints the output and re-prompts the user for the next input.

Here’s a simplified pseudocode of the main loop:

``` bash
Initialize program
----------------------------
while (1)
{
    0) Wait for user input 
    1) Check syntax
    2) Tokenize input
    3) Build AST from tokens
    4) Traverse AST and execute commands
    5) Reset and re-prompt
}
----------------------------
Clean up and exit

```

For more details click, [**here**](https://github.com/Mecha-Coder/42-minishell/blob/main/demo/minishell.pptx)

---

### **Demo**

![demo](https://github.com/Mecha-Coder/42-minishell/blob/main/demo/demo.gif)

---

### **Feature** 
- Command history
- Input/output redirection and heredoc
- Pipes
- Variable and wildcard (*) expansion
- Logical AND (&&) and OR (||) operators
- Subshell execution
- Signal handling (e.g., Ctrl + C, Ctrl + D)

--- 

### **Contribution**
- Implemented local environment
- Syntax checking
- Tokenization logic
- AST construction
- Command execution
- Variable and wildcard expansion
- Input/output redirection
- Test case preparation


**Teammate with :** 
- John Tan (https://github.com/jjohntan)

--- 


### **How to run**

System requirement: **Debian/Ubuntu/WSL2**


```bash
# Install dependencies
sudo apt-get install libreadline-dev

# Clone the repository
git clone https://github.com/Mecha-Coder/42-minishell
cd 42-minishell

# Build the program
make

# Launch the shell
./minishell

```
---

### **Resource**

