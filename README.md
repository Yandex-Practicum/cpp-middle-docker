# cpp-middle-docker <!-- omit in toc -->

- [Пререквизиты](#пререквизиты)
- [Начало работы](#начало-работы)
- [Сборка проекта и запуск тестов](#сборка-проекта-и-запуск-тестов)
  - [Команды для сборки проекта](#команды-для-сборки-проекта)
  - [Команды для запуска приложения](#команды-для-запуска-приложения)
  - [Дополнительно](#дополнительно)


Шаблон репозитория с докер контейнером для выполнения заданий курса «Мидл разработчик С++»

## Пререквизиты

Для работы с проектом вам понадобится установить всего один инструмент - Docker.
Основное преимущество использования Docker - вам не нужно настраивать зависимости вручную или устанавливать сторонние библиотеки на вашу систему, поскольку всё необходимое для сборки и запуска проекта уже описано в файле Dockerfile. Использование Docker позволяет:

- Предоставить всем разработчикам унифицированную среду разработки и выполнения вне зависимости от используемой ОС или имеющихся библиотек
- Обеспечить простоту использования: окружение настроено и сконфигурировано, а вам остаётся лишь запустить Docker контейнер и использовать его
- Безопасность и чистоту системы: ничего лишнего не устанавливается напрямую


Для установки Docker воспользуйтесь следующими ссылками:

- [Скачать Docker Desktop ( Windows/Mac )](https://www.docker.com/products/docker-desktop/)

- [Скачать Docker ( Ubuntu/Debian/... )](https://docs.docker.com/engine/install/)

После установки Docker переходите к разделу: `Начало работы`.

## Начало работы

1. Нажмите зелёную кнопку `Use this template`, затем `Create a new repository`.
2. Назовите свой репозиторий.
3. Склонируйте созданный репозиторий командой `git clone your-repository-name`.
4. Создайте новую ветку командой `git switch -c development`.
5. Откройте проект в `Visual Studio Code`.
6. Нажмите `F1` и откройте проект в dev-контейнере командой `Dev Containers: Reopen in Container`.


![Скриншот 1](misc/image_3.png)

## Сборка проекта и запуск тестов

Данный репозиторий использует два инструмента:

- **Conan** — свободный менеджер пакетов для C и C++ с открытым исходным кодом (MIT). Позволяет настраивать процесс сборки программ, скачивать и устанавливать сторонние зависимости и необходимые инструменты. Подробнее о Conan:
  - https://habr.com/ru/articles/884464
  - https://docs.conan.io/2.0/tutorial/consuming_packages/build_simple_cmake_project.html
  - https://docs.conan.io/2.0/tutorial/consuming_packages/the_flexibility_of_conanfile_py.html
- **cmake** — генератор систем сборки для C и C++. Позволяет создавать проекты, которые могут компилироваться на различных платформах и с различными компиляторами. Подробнее о cmake:
  - https://dzen.ru/a/ZzZGUm-4o0u-IQlb
  - https://neerc.ifmo.ru/wiki/index.php?title=CMake_Tutorial
  - https://cmake.org/cmake/help/book/mastering-cmake/cmake/Help/guide/tutorial/index.html

### Команды для сборки проекта

Используйте `F5` для выполнения следующих шагов:
- Создание папки `build`
- Вызов `conan` команд для установки требуемых библиотек и запуска процесса сборки
- Запуска `lldb` отладчика

### Команды для запуска приложения

```bash
cd build
./app 
```

### Дополнительно

- Автодополнение `Ctrl + Space`. Для настройки автодополнения вам необходимо нажать `F1` и выполнить команду `clangd: Download language server`. VS Code сам предложит установить подходящую версию `clangd` (всплывашка в правом нижнем углу). После завершения установки потребуется перезагрузить окно (кнопка перезапуска будет находиться также справа снизу или нажать `F1` и выполнить команду `Developer: Reload Window`)

Если всё сделано правильно - после успешной сборки проекта вы сможете использовать автодополнение:

![Скриншот 2](misc/image_1.png)

![Скриншот 3](misc/image_2.png)
