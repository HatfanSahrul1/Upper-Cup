# Tugas Akhir Mata Kuliah Design Pattern
## Oscar Javier Abdullah	(5223600001)
## Hatfan Sahrul Ramadhan	(5223600004)
Proyek ini merupakan implementasi tugas akhir untuk mata kuliah **Design Pattern**. Aplikasi dikembangkan menggunakan bahasa C++ dengan bantuan library **raylib** untuk keperluan grafis, serta menerapkan berbagai pola desain perangkat lunak (design patterns) seperti:

- Singleton
- Factory
- State

## 📦 Struktur Proyek
```bash
project-root/
│
├── game/
│ └── src/ # Source code utama
│
├── image/ # Gambar/asset (cup.png, dll)
│
├── build/ # Folder hasil build (berisi game.exe)
│
├── CMakeLists.txt # Konfigurasi build (CMake)
│
└── README.md # Dokumentasi
```

## ▶️ Cara Menjalankan

1. **Build proyek dengan CMake**
   ```bash
   mkdir build
   cd build
   cmake ..
   mingw32-make
   game.exe
	```