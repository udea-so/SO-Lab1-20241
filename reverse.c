int main(int argc, char *argv[]) {
    limpiarPantalla();
    mostrarAnimacion();
    mostrarPresentacion();
    esperarTecla();
    flujoPrograma(argc, argv);
    esperarTecla();
    limpiarPantalla();
    return 0;
}