import os
import platform
import shutil
import subprocess
import sys

PROJECT_NAME = "shiny-spoon"
BUILD_DIR = "build"

def check_command(cmd):
    return shutil.which(cmd) is not None

def run_cmd(cmd, cwd=None):
    print(f"[RUN] {' '.join(cmd)}")
    result = subprocess.run(cmd, cwd=cwd)
    if result.returncode != 0:
        sys.exit(result.returncode)

def main():
    system = platform.system()

    # 检查 CMake
    if not check_command("cmake"):
        print("❌ CMake 未安装或未加入 PATH")
        sys.exit(1)

    # 检查编译器
    if system == "Windows":
        if not (check_command("cl") or check_command("g++")):
            print("❌ 未检测到 MSVC (cl) 或 MinGW (g++) 编译器")
            sys.exit(1)
    else:
        if not check_command("g++"):
            print("❌ 未检测到 g++ 编译器")
            sys.exit(1)

    # 创建 build 目录
    if not os.path.exists(BUILD_DIR):
        os.makedirs(BUILD_DIR)

    # 运行 CMake
    if system == "Windows" and check_command("cl"):
        run_cmd(["cmake", ".."], cwd=BUILD_DIR)
    elif system == "Windows" and check_command("g++"):
        run_cmd(["cmake", "..", "-G", "MinGW Makefiles"], cwd=BUILD_DIR)
    else:
        run_cmd(["cmake", ".."], cwd=BUILD_DIR)

    # 编译
    run_cmd(["cmake", "--build", ".", "--config", "Release"], cwd=BUILD_DIR)

    # 运行可执行文件
    exe_name = PROJECT_NAME + (".exe" if system == "Windows" else "")
    exe_path = os.path.join(BUILD_DIR, exe_name)
    if os.path.exists(exe_path):
        run_cmd([exe_path])
    else:
        print(f"❌ 未找到可执行文件: {exe_path}")

if __name__ == "__main__":
    main()