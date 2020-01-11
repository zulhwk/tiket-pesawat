# tiket-pesawat
Program pemesanan tiket pesawat menggunakan bahasa C++ dengan database MySQL.



# CARA PENGGUNAAN :
1. Download semua File diatas.
2. Extract LIBRARY MYSQL C++.rar
3. Copy File libmysql.a kedalam folder instalasi codeblocks :

   C:\Program Files (x86)\CodeBlocks\MinGW\lib
   
4. Copy File sisanya kedalam :

   C:\Program Files (x86)\CodeBlocks\MinGW\include
   
5. Buka CodeBlocks anda, lalu open file .cbp yang telah di download.

# INSTALASI :
1. Setelah dibuka file project .cbp nya, lalu selanjutnya yaitu untuk men-setting library mysql kedalam project anda.
2. Klik Project yang ada di menu atas lalu klik Build Options.
3. Pada panel Linker Settings, klik ADD lalu arahkan file libmysql.a tadi. Jika muncul menu "Keep this as a Relative Path?" pilih No.
4. Selanjutnya, klik tab Search Directories, klik ADD, lalu arahkan pada folder include saja. Lalu klik NO.

Jangan lupa untuk upload database tiket_pesawat.sql terlebih dahulu kedalam MySQL nya.

Setelah itu RUN, untuk pertama akan muncul error, lalu copy file libmysql.dll kedalam project yang telah didownload tadi kedalam :

namaproject/bin/debug/

atau :

namaproject/obj/debug/
