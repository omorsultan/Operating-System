dir=/home/omor/os/shell_scripting

total_file=$(find "$dir" -maxdepth 1 -type f | wc -l)
# (find "$dir" -maxdepth 1 -type f | wc -l)
total_dir=$(find "$dir" -maxdepth 1 -type d | wc -l)
total_dir=$((total_dir - 1))
echo "total file is : $total_file"
echo "total dir is : $total_dir "