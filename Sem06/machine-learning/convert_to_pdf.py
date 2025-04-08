#!/usr/bin/env python3
"""
Convert Jupyter notebooks to PDF with A4 size pages.
Usage: python jupyter_to_pdf.py notebook.ipynb
"""

import sys
import os
import subprocess
import tempfile
from pathlib import Path

def convert_notebook_to_pdf(notebook_path):
    """
    Convert a Jupyter notebook to PDF with A4 size format.
    
    Args:
        notebook_path (str): Path to the Jupyter notebook file
    
    Returns:
        str: Path to the generated PDF file
    """
    notebook_path = Path(notebook_path)
    
    if not notebook_path.exists():
        print(f"Error: File '{notebook_path}' not found")
        sys.exit(1)
    
    if notebook_path.suffix.lower() != '.ipynb':
        print(f"Error: '{notebook_path}' is not a Jupyter notebook file")
        sys.exit(1)
    
    # Create a temporary directory for the conversion process
    with tempfile.TemporaryDirectory() as temp_dir:
        # First convert notebook to HTML
        html_path = os.path.join(temp_dir, f"{notebook_path.stem}.html")
        print(f"Converting {notebook_path} to HTML...")
        
        cmd = [
            "jupyter", "nbconvert", 
            "--to", "html", 
            str(notebook_path),
            "--output", html_path
        ]
        
        result = subprocess.run(cmd, capture_output=True, text=True)
        
        if result.returncode != 0:
            print(f"Error converting to HTML: {result.stderr}")
            sys.exit(1)
        
        # Then convert HTML to PDF with A4 size using wkhtmltopdf
        pdf_path = str(notebook_path.with_suffix('.pdf'))
        print(f"Converting HTML to PDF with A4 size...")
        
        cmd = [
            "wkhtmltopdf",
            "--page-size", "A4",
            html_path, pdf_path
        ]
        
        result = subprocess.run(cmd, capture_output=True, text=True)
        
        if result.returncode != 0:
            print(f"Error converting to PDF: {result.stderr}")
            sys.exit(1)
        
        print(f"Successfully converted to PDF: {pdf_path}")
        return pdf_path

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} notebook.ipynb")
        sys.exit(1)
    
    convert_notebook_to_pdf(sys.argv[1])