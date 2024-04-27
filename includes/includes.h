#include <string.h>
#include <errno.h>
#include "../config/config.h"
#include "../lib/orm/orm.h"
#include "../lib/orm/query.h"
#include "../lib/utils/utils.h"
/* incluir los archivos que representen las entidades */

#include "../src/localidad/localidad.h"
#include "../src/pais/pais.h"
#include "../src/forma_pago/forma_pago.h"
#include "../src/agencia/agencia.h"
#include "../src/turista/turista.h"
#include "../src/tipo_paquete/tipo_paquete.h"
#include "../src/agencia_tipo_paq/agencia_t_paquete.h"
#include "../src/tipo_actividad/tipo_actividad.h"
#include "../src/tipo_paquete_tipo_actividad/tipo_paquete_tipo_actividad.h"
#include "../src/transporte/transporte.h"
#include "../src/actividad/actividad.h"
#include "../src/paquete/paquete.h"
#include "../src/paquete_actividad/paquete_actividad.h"
#include "../src/factura_turista/factura_turista.h"
#include "../src/det_factura_turista/det_factura_turista.h"

#include "../view/view.h"
#include "../cmp/cmp.h"
#include "../insertar/insertar.h"
#include "../actualizar/actualizar.h"
#include "../seleccionar/seleccionar.h"
#include "../verificaciones/verifica.h"

