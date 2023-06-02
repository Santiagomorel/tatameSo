#include "servidor.h"

int main() {
    
    server_log = log_create("./runlogs/server.log", "SERVER", 1, LOG_LEVEL_TRACE);

    socket_servidor = iniciar_servidor(PUERTO, server_log);
    socket_cliente = esperar_cliente(socket_servidor, server_log);
    
    
    while(1) {
        int codigoOperacion = recibir_operacion(socket_cliente);
        switch(codigoOperacion)
            {
            case EJECUTAR_CE:
                contexto_ejecucion * ce = recibir_ce(socket_cliente);
                imprimir_ce(ce, server_log);
                break;
            default:
                //log_trace(log_memoria, "recibi el op_cod %d y entro DEFAULT", codigoOperacion);
                break;
        }
    }
    
    return 0;
}
