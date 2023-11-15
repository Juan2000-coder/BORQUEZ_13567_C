# Cliente y Servidor XML-RPC con generador de numeros.

## Descripción General

    Es una aplicación en C++ que opera en un servidor XML-RPC diseñada para generar números aleatorios 
    segun las peticiones que hace un usuario a través de un cliente CML-RPC. La aplicación ofrece funcionalidades
    para generar tanto enteros como números reales dentro de rangos especificados. Opera como un servidor
    utilizando comunicación XML-RPC, lo que permite a clientes remotos solicitar generación de números,
    información estadística, listado de números y más. Los componentes del servidor y del cliente permiten
    una comunicación fluida sobre una red local.

## Características

- Generación de números enteros y reales aleatorios dentro de rangos especificados.
- Arquitectura cliente-servidor utilizando XML-RPC para comunicación remota.
- Obtención de información estadística sobre los números generados.
- Listado y retorno de números generados.
- Soporte para ejecución únicamente en la red local.

## Requisitos Previos

Para construir y ejecutar el *Generador de Números XML-RPC Server* y el *Cliente XML-RPC*, necesitarás lo siguiente:

- Compilador de C++ que admita el estándar C++11.
- GNU Make.


## Instrucciones de Instalación

A continuación se detallan los pasos necesarios para instalar la aplicación.
Asegúrate de tener las dependencias necesarias antes de comenzar.

### 0. Construccion completa
    Directamente ejecuta en el directorio de la solución.
        make

### 1. Construcción de la Librería XML-RPC

#### a. Construir la Librería xmlrpc

    1. Navega al directorio raíz de la solución.
    2. Ejecuta el siguiente comando para construir la librería XML-RPC:
        make xmlrpc
   
#### b. Incorporar Archivos
    Si ya tienes la librería xmlrpc. Incorpora los archivos de encabezado (headers) de XML-RPC++ en la carpeta
    ./include/xmlrpc y sobrescribe los que alli se encuentran. Sobrescribe los archivos fuente en ./src/xmlrpc
    con los archivos proporcionados por la libreria de XML-RPC++.

    Ejecuta:
        make
    Para construir la libreria y los ejecutables del cliente y el servidor.

### 2. Construcción del Cliente y del Servidor

#### a. Construir el Cliente
    Ejecuta el siguiente comando para construir el cliente:
        make client

#### b. Construir el Servidor
    Ejecuta el siguiente comando para construir el servidor:
        make server

### 3. Localización de los archivos
    Encuentra los ejecutables generados en la carpeta ./build.
    Los archivos objetos en ./bin
    Y la libreria de xmlrpc en ./lib

### 4. Limpiar ejecutables y objetos
    Se pueden eliminar los ejecutables y objetos generador haciendo:
        make clean