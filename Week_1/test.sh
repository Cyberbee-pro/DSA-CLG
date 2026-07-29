#!/bin/bash

# Configuration
SOURCE="impStruc.c"
OUTPUT="student_test"

echo "=========================================="
echo " 1. Compiling $SOURCE"
echo "=========================================="

# Compile with strict warnings to catch potential memory/type bugs
gcc -Wall -Wextra -std=c99 "$SOURCE" -o "$OUTPUT"

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo -e "\n❌ Compilation failed! Please fix the errors above."
    exit 1
fi

echo -e "✅ Compilation successful!\n"

echo "=========================================="
echo " 2. Running Automated Test Case"
echo "=========================================="

# Pipe test inputs directly into the compiled executable
./"$OUTPUT" << 'EOF'
3
RA5467
Shibraj Das
18
89
90
99
90
90
RA43667
Devansh Sahu
19
78
98
79
80
79
RA243567
Shristh Rana
19
89
78
76
87
77
EOF

echo -e "\n=========================================="
echo " 3. Cleanup"
echo "=========================================="

# Remove the compiled binary
rm -f "$OUTPUT"
echo "Cleaned up executable binary."
