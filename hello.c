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
