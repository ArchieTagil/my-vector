# Инструкция по работе с проектом:
1. .h файл с вашей библиотекой размещать в src/containers, если у вас несколько файлов, лучше создать папку и поправить Makefile
2. Тесты размещать в папке test/functional_tests, опять же предлагаю либо 1 файл, либо папку, на подобии как я сделал с вектором.
3. После добавления файла с вашим контейнером в src/containers не забудьте его заинклудить в test/test.h, больше вроде ничего не нужно, просто запускаете make и тесты собираются с подключенным вашим заголовочным файлом.