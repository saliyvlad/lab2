#!/bin/bash

# Ввод названия каталога
read -p "Введите название каталога: " dirname

# Проверка существования каталога
if [ -d "$dirname" ]; then
    echo "Каталог $dirname существует."
else
    echo "Каталог $dirname не существует."
    exit 1
fi

# Поиск файла, имя которого начинается с символа 'a'
file=$(find "$dirname" -type f -name "a*")
if [ -z "$file" ]; then
    echo "Файл, начинающийся с 'a', не найден."
    exit 1
fi

echo "Найден файл: $file"

# Замена знаков пунктуации на '#'
tr -c '[:alnum:][:space:]' '#' < "$file" > "${file%.txt}.UP"

# Сохранение в каталог Z54
mv "${file%.txt}.UP" "Z54/"

echo "Преобразованный файл сохранен в каталоге Z54 с именем ${file##*/}.UP"




#!/bin/bash

# Ввод названия каталога
read -p "Введите название каталога: " dir_name

# Проверка существования каталога
if [ -d "$dir_name" ]; then
    echo "Каталог существует."
else
    echo "Каталог не существует."
    exit 1
fi

# Поиск файла, начинающегося с 'a'
file=$(find "$dir_name" -type f -name 'a*' | head -n 1)

if [ -z "$file" ]; then
    echo "Файл не найден."
    exit 1
fi

# Замена знаков пунктуации на '#'
new_file="${file%.txt}.UP"  # Предполагается, что файл имеет расширение .txt
tr -c '[:alnum:][:space:]' '#' < "$file" > "$new_file"

echo "Преобразованный файл сохранен как $new_file."
