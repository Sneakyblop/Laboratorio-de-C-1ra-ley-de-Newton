#ifndef SIMULADOR_H
#define SIMULADOR_H

#define G_UNIVERSAL 6.674e-11
#define MASA_TIERRA 5.972e24
#define MASA_LUNA 7.342e22
#define RADIO_TIERRA 6371000.0
#define MASA_ORION_KG 26000.0
#define ALTITUD_ORBITA_M 192000.0
#define DISTANCIA_TIERRA_LUNA_M 384000000.0
#define VELOCIDAD_TLI_MS 10900.0
#define MAX_REGISTROS 50

typedef struct
{
    double masa;
    double velocidad;
    double energia;
} RegistroEnergia;

typedef struct
{
    double distanciaEquilibrio;
    double trabajoPorMasa;
} RegistroTrabajo;

typedef struct
{
    double distanciaKm;
    double velocidad;
    double tiempoSegundos;
} RegistroTiempo;

typedef struct
{
    RegistroEnergia energias[MAX_REGISTROS];
    int cantidadEnergias;
    RegistroTrabajo trabajos[MAX_REGISTROS];
    int cantidadTrabajos;
    RegistroTiempo tiempos[MAX_REGISTROS];
    int cantidadTiempos;
} Reporte;

double calcularEnergiaCinetica(double masa, double velocidad);
int calcularTrabajoPorMasa(double altitud, double distancia,
                           double velocidadInicial,
                           double *distanciaEquilibrio,
                           double *trabajoPorMasa);
void inicializarReporte(Reporte *reporte);
int registrarEnergia(Reporte *reporte, double masa, double velocidad,
                     double energia);
int registrarTrabajo(Reporte *reporte, double distanciaEquilibrio,
                     double trabajoPorMasa);
int registrarTiempo(Reporte *reporte, double distanciaKm, double velocidad,
                    double tiempoSegundos);
void mostrarReporte(const Reporte *reporte);

#endif 