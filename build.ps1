$null = New-Item -ItemType Directory -Force build
clang -Wall -Werror -pedantic -o build/hanc_test_example.exe hanc_test/hanc_test_example.c
clang -Wall -Werror -pedantic -DHANC_TEST -o build/hanc_test_example_test.exe hanc_test/hanc_test_example.c
Write-Host "Build finished!"
