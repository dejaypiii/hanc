$null = New-Item -ItemType Directory -Force build
Write-Host "Building hanc test example with gcc..."
gcc -std=c17 -Wall -Werror -pedantic -o build/hanc_test_example_gcc.exe hanc_test/add.c hanc_test/hanc_test_example.c 
Write-Host "Building hanc test example tests with gcc..."
gcc -std=c17 -Wall -Werror -pedantic -DHANC_TEST -o build/hanc_test_example_test_gcc.exe hanc_test/add.c hanc_test/hanc_test_example.c
Write-Host "Build finished!"
