### Team Template Generator

This script allows you to generate a PDF notebook of your competitive programming algorithms and code snippets. It is based on the work by hamza-28 and has been modified for enhanced organization.

### Repository Structure

The code is organized by topic in the `code/` directory:

### Required Packages

To compile and generate the PDF template, you need the following:

*   **python3**
    *   Debian/Ubuntu/Mint: `sudo apt-get install python3`
    *   RHEL/CentOS/Fedora: `sudo dnf install python3`

*   **texlive-full** (for LaTeX compilation)
    *   Debian/Ubuntu/Mint: `sudo apt-get install texlive-full`
    *   RHEL/CentOS/Fedora: `sudo dnf install texlive-scheme-full`

*   **pygments** (for syntax highlighting)
    *   Debian/Ubuntu/Mint:
        ```bash
        sudo apt-get install python3-pip
        pip3 install pygments
        ```
    *   RHEL/CentOS/Fedora:
        ```bash
        sudo dnf install python3-pip
        pip3 install pygments
        ```
    *   **Troubleshooting**: If you encounter issues, consider installing `pygments` in a virtual environment:
        ```bash
        sudo apt install python3-venv
        python3 -m venv venv
        source venv/bin/activate
        pip3 install pygments
        ```

### How To Use

1.  Add your `.cpp` or code files into the appropriate subdirectory within the `code/` folder.
2.  Open a terminal in the project root directory.
3.  Run the generation script:
    ```bash
    python3 main.py
    ```
4.  The output `notebook.pdf` will be generated in the root directory.

### Customization

To customize the look and feel or the metadata of the PDF:

*   **Edit `template/template.tex`**:
    *   **Team & Contest Info**: Change lines 4-11.
    *   **Font Size**: Edit line 1 or change `scaled=..` in line 21.

