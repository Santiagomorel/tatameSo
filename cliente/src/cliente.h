#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <utils/utils.h>

#define PUERTO "9000"

t_log* cliente_log;
int conexion;

t_pcb* pcb;
contexto_ejecucion* nuevoContexto;

t_pcb *pcb_create();

t_registro * crear_registros();

// void copiar_a_registro4(char[4]* , char*);

contexto_ejecucion* obtener_ce(t_pcb *);
void copiar_registros_pcb_a_ce(t_pcb*, contexto_ejecucion*);
void copiar_registros_ce_a_pcb(contexto_ejecucion*, t_pcb*);
void copiar_instrucciones_pcb_a_ce(t_pcb *, contexto_ejecucion *);
void copiar_instrucciones_ce_a_pcb(contexto_ejecucion *, t_pcb *);
void copiar_id_pcb_a_ce(t_pcb* , contexto_ejecucion* );
void copiar_id_ce_a_pcb(contexto_ejecucion* , t_pcb* );
void copiar_PC_pcb_a_ce(t_pcb* , contexto_ejecucion* );
void copiar_PC_ce_a_pcb(contexto_ejecucion* , t_pcb* );
#endif