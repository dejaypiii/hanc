Write-Host "Building hanc test example with msvc..."
cl /std:c17 /W4 /WX /permissive- /Fe: .\build\hanc_test_example_msvc.exe hanc_test\add.c hanc_test\hanc_test_example.c
Write-Host "Building hanc test example tests with msvc..."
cl /std:c17 /W4 /WX /permissive- /DHANC_TEST /Fe: .\build\hanc_test_example_test_msvc.exe hanc_test\add.c hanc_test\hanc_test_example.c 
Write-Host "Build finished!"
