void esperarTecla() {
    printf("\nPresiona una tecla para continuar...");
    getchar();  // Espera a la pulsación una tecla
}

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