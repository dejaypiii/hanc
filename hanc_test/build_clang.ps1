$null = New-Item -ItemType Directory -Force build
Write-Host "Building hanc test example with clang..."
clang -std=c17 -Wall -Werror -pedantic -o build/hanc_test_example_clang.exe example/add.c example/hanc_test_example.c 
Write-Host "Building hanc test example tests with clang..."
clang -std=c17 -Wall -Werror -pedantic -target x86_64-pc-windows-gnu -DHANC_TEST -o build/hanc_test_example_test_clang.exe example/add.c example/hanc_test_example.c
Write-Host "Build finished!"
