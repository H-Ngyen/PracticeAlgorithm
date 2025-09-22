import os

def clear_exe_files(root_dir):
    deleted_count = 0
    for folder, _, files in os.walk(root_dir):
        for filename in files:
            if filename.lower().endswith(".exe"):
                file_path = os.path.join(folder, filename)
                try:
                    os.remove(file_path)
                    print(f"Đã xóa: {file_path}")
                    deleted_count += 1
                except Exception as e:
                    print(f"Lỗi khi xóa {file_path}: {e}")
    print(f"\nHoàn tất. Đã xóa {deleted_count} file .exe.")

if __name__ == "__main__":
    target_directory = r"D:\Workspace\algorithm"
    clear_exe_files(target_directory)
