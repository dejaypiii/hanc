Write-Host "Building hanc test example with msvc..."
cl /std:c17 /W4 /WX /permissive- /Fo".\\build\\" /Fe: .\build\hanc_test_example_msvc.exe example\add.c example\hanc_test_example.c
Write-Host "Building hanc test example tests with msvc..."
cl /std:c17 /W4 /WX /permissive- /DHANC_TEST /Fo".\\build\\" /Fe: .\build\hanc_test_example_test_msvc.exe example\add.c example\hanc_test_example.c 
Write-Host "Build finished!"
