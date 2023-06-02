#include "cliente.h"

int main(int argc, char* argv[]) {
    cliente_log = log_create("./runlogs/client.log", "CLIENTE", 1, LOG_LEVEL_TRACE);

    conexion = crear_conexion(IP, "9001");
    pcb = pcb_create();
    nuevoContexto = obtener_ce(pcb);
    imprimir_ce(nuevoContexto, cliente_log);
    enviar_ce(conexion, nuevoContexto, EJECUTAR_CE, cliente_log);
    return 0;
}


t_pcb *pcb_create()
{
    log_trace(cliente_log, "creo el pcb");
    t_pcb *new_pcb = malloc(sizeof(t_pcb));

    new_pcb->registros_cpu = crear_registros();
    // new_pcb->tabla_paginas = -1; // TODO de la conexion con memoria

    return new_pcb;
}

t_registro * crear_registros() {
    t_registro * nuevosRegistros = malloc(sizeof(t_registro));
    // copiar_a_registro4(nuevosRegistros->AX, char*);
    strcpy(nuevosRegistros->AX , "SACA");
    strcpy(nuevosRegistros->BX , "SCBA");
    strcpy(nuevosRegistros->CX , "SLCA");
    strcpy(nuevosRegistros->DX , "SMNA");
	strcpy(nuevosRegistros->EAX , "SERMINAR");
	strcpy(nuevosRegistros->EBX , "APMAMAMR");
	strcpy(nuevosRegistros->ECX , "ETETEER");
	strcpy(nuevosRegistros->EDX , "PLUGLUGR");
	strcpy(nuevosRegistros->RAX , "PUMAMAMEMIMAAZXT");
	strcpy(nuevosRegistros->RBX , "PORFAVORFUNCIONA");
	strcpy(nuevosRegistros->RCX , "PELOPIDOPORFAVOR");
	strcpy(nuevosRegistros->RDX , "PLSSTOPIAMINPAIN");
    return nuevosRegistros;
}

// void copiar_a_registro4(char[4]* registro, char* string) {
//     strcpy(registro , string);
// }

contexto_ejecucion * obtener_ce(t_pcb * pcb){ // PENSAR EN HACERLO EN   AMBOS SENTIDOS
    contexto_ejecucion * nuevoContexto = malloc(sizeof(contexto_ejecucion));
    nuevoContexto->registros_cpu = malloc(sizeof(t_registro));
    copiar_registros_pcb_a_ce(pcb, nuevoContexto);
    return nuevoContexto;
}

void copiar_instrucciones_pcb_a_ce(t_pcb * pcb, contexto_ejecucion * ce) { //copia instrucciones de la estructura 1 a la 2
    for (int i = 0; i < string_array_size(pcb->instrucciones); i++) {
        // log_trace(kernel_logger, "copio en ce %s", pcb->instrucciones[i]);
        string_array_push(&(ce->instrucciones), string_duplicate(pcb->instrucciones[i]));
    }
}

void copiar_instrucciones_ce_a_pcb(contexto_ejecucion * ce, t_pcb * pcb) { //copia instrucciones de la estructura 1 a la 2
    for (int i = 0; i < string_array_size(ce->instrucciones); i++) {
        // log_trace(kernel_logger, "copio en pcb %s", ce->instrucciones[i]);
        string_array_push(&(pcb->instrucciones), string_duplicate(ce->instrucciones[i]));
    }
}

void copiar_registros_pcb_a_ce(t_pcb * pcb, contexto_ejecucion * ce) {
    strcpy(ce->registros_cpu->AX , pcb->registros_cpu->AX);
    strcpy(ce->registros_cpu->BX , pcb->registros_cpu->BX);
    strcpy(ce->registros_cpu->CX , pcb->registros_cpu->CX);
    strcpy(ce->registros_cpu->DX , pcb->registros_cpu->DX);
	strcpy(ce->registros_cpu->EAX , pcb->registros_cpu->EAX);
	strcpy(ce->registros_cpu->EBX , pcb->registros_cpu->EBX);
	strcpy(ce->registros_cpu->ECX , pcb->registros_cpu->ECX);
	strcpy(ce->registros_cpu->EDX , pcb->registros_cpu->EDX);
	strcpy(ce->registros_cpu->RAX , pcb->registros_cpu->RAX);
	strcpy(ce->registros_cpu->RBX , pcb->registros_cpu->RBX);
	strcpy(ce->registros_cpu->RCX , pcb->registros_cpu->RCX);
	strcpy(ce->registros_cpu->RDX , pcb->registros_cpu->RDX);
}

void copiar_registros_ce_a_pcb(contexto_ejecucion * ce, t_pcb * pcb) {
    strcpy(pcb->registros_cpu->AX , ce->registros_cpu->AX);
    strcpy(pcb->registros_cpu->BX , ce->registros_cpu->BX);
    strcpy(pcb->registros_cpu->CX , ce->registros_cpu->CX);
    strcpy(pcb->registros_cpu->DX , ce->registros_cpu->DX);
	strcpy(pcb->registros_cpu->EAX , ce->registros_cpu->EAX);
	strcpy(pcb->registros_cpu->EBX , ce->registros_cpu->EBX);
	strcpy(pcb->registros_cpu->ECX , ce->registros_cpu->ECX);
	strcpy(pcb->registros_cpu->EDX , ce->registros_cpu->EDX);
	strcpy(pcb->registros_cpu->RAX , ce->registros_cpu->RAX);
	strcpy(pcb->registros_cpu->RBX , ce->registros_cpu->RBX);
	strcpy(pcb->registros_cpu->RCX , ce->registros_cpu->RCX);
	strcpy(pcb->registros_cpu->RDX , ce->registros_cpu->RDX);
}

void copiar_id_pcb_a_ce(t_pcb* pcb, contexto_ejecucion* ce) {
    ce->id = pcb->id;
}

void copiar_id_ce_a_pcb(contexto_ejecucion* ce, t_pcb* pcb) {
    pcb->id = ce->id;
}

void copiar_PC_pcb_a_ce(t_pcb* pcb, contexto_ejecucion* ce) {
    ce->program_counter = pcb->program_counter;
}

void copiar_PC_ce_a_pcb(contexto_ejecucion* ce, t_pcb* pcb) {
    pcb->program_counter = ce->program_counter;
}