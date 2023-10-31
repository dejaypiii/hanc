$null = New-Item -ItemType Directory -Force build
Write-Host "Building program with clang..."
clang -std=c17 -Wall -Werror -pedantic -o build/hanc_test_example_clang.exe hanc_test/add.c hanc_test/hanc_test_example.c 
Write-Host "Building tests with clang..."
clang -std=c17 -Wall -Werror -pedantic -target x86_64-pc-windows-gnu -DHANC_TEST -o build/hanc_test_example_test_clang.exe hanc_test/add.c hanc_test/hanc_test_example.c
Write-Host "Build finished!"
