
# Command-Line Basics Documentation

This document provides an overview of some common command-line commands, their usage, and examples.

## 1. `ls`

### **Description**
The `ls` command lists the files and directories in the current directory.

### **Usage**
```bash
ls
```

### **Options**
- `ls -l`: Lists files in long format, showing detailed information.
- `ls -a`: Lists all files, including hidden files (those starting with `.`).

### **Example**
```bash
ls -l
```

## 2. `cd`

### **Description**
The `cd` command is used to change the current directory.

### **Usage**
```bash
cd [directory]
```

### **Example**
```bash
cd Documents
```

## 3. `pwd`

### **Description**
The `pwd` command prints the current working directory.

### **Usage**
```bash
pwd
```

### **Example**
```bash
pwd
```

## 4. `mkdir`

### **Description**
The `mkdir` command creates a new directory.

### **Usage**
```bash
mkdir [directory_name]
```

### **Example**
```bash
mkdir new_folder
```

## 5. `rm`

### **Description**
The `rm` command removes files or directories.

### **Usage**
```bash
rm [file_name]
```

### **Options**
- `rm -r [directory_name]`: Removes a directory and its contents recursively.

### **Example**
```bash
rm file.txt
rm -r old_folder
```

## 6. `cp`

### **Description**
The `cp` command copies files or directories.

### **Usage**
```bash
cp [source] [destination]
```

### **Example**
```bash
cp file.txt /home/user/backup/
```

## 7. `mv`

### **Description**
The `mv` command moves or renames files or directories.

### **Usage**
```bash
mv [source] [destination]
```

### **Example**
```bash
mv old_name.txt new_name.txt
mv file.txt /home/user/Documents/
```

## 8. `cat`

### **Description**
The `cat` command concatenates and displays the contents of files.

### **Usage**
```bash
cat [file_name]
```

### **Example**
```bash
cat file.txt
```

## 9. `nano`

### **Description**
The `nano` command opens a text editor for creating or modifying files.

### **Usage**
```bash
nano [file_name]
```

### **Example**
```bash
nano file.txt
```
