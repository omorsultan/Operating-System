dir=/home/omor/os/synchronization


countFiles=$(find $dir -type f | wc -l)  # '|' -> Pipe and wc -l → counts how many lines are output (each file = 1 line)
countDir=$(find $dir -type d | wc -l)
countDir=$((countDir - 1)) # exclude the main directory

echo "📂 Directory: $dir"
echo "🗂️ Files:$countFiles"
echo "📦 Subdirectories: $countDir"

total_files=$(find "$dir" -maxdepth 1 -type f | wc -l)
total_dirs=$(find "$dir" -maxdepth 1 -type d | wc -l)
total_dirs=$((total_dirs - 1))  # exclude current directory

echo "Files: $total_files"
echo "Directories: $total_dirs"
