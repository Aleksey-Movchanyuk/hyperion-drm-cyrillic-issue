# hyperion-drm-cyrillic-issue


`ChangeLocale.dll` is a lightweight dynamic-link library (DLL) designed to fix encoding issues in older programs by changing the thread locale to a specific locale (in this case, Russian) to ensure proper encoding and display of text in applications that may not natively support Unicode or other modern character encodings.

## Usage
To use `ChangeLocale.dll` with `dll_inject.exe`, follow these steps:

1. Build the `ChangeLocale.dll` file using the provided CMake build system. This can be done by executing the following commands in the project directory:
   ```
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
   This will generate a `ChangeLocale.dll` file in the *dist* directory.

1. Download or compile dll_inject.exe. Make sure it's located in a directory accessible via the command line.

1. Open a command prompt and navigate to the directory containing dll_inject.exe.

1. Execute the following command to inject ChangeLocale.dll into the target process (mdm_ntier_client_http.exe in this example):

   ```
   dll_inject.exe ChangeLocale.dll mdm_ntier_client_http.exe
   ```

`ChangeLocale.dll` will be injected into the target process, and the thread locale will be changed to the desired locale, fixing any encoding issues.

## Note 
This solution may not work for all programs and should be tested on a case-by-case basis.

## Customization
If you need to change the target locale, you can modify the ChangeLocale.cpp file to use a different locale. Replace LANG_RUSSIAN with the desired language identifier and rebuild the DLL.

For example, to change the target locale to English (United States), replace LANG_RUSSIAN with LANG_ENGLISH and SUBLANG_DEFAULT with SUBLANG_ENGLISH_US:

```
SetThreadLocale(
    MAKELCID(
        MAKELANGID(
            LANG_ENGLISH,
            SUBLANG_ENGLISH_US
        ),
        SORT_DEFAULT
    )
);
```

Rebuild the DLL following the steps in the "Usage" section.