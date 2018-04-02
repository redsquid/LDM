#include "GaussTable.h"

GaussTable GaussTable::INSTANCE(GaussTable::ORDER);

GaussTable::GaussTable(uint order) :
    GAUSS_TABLE(gsl_integration_glfixed_table_alloc(order))
{

}

GaussTable::~GaussTable() {
    gsl_integration_glfixed_table_free(const_cast<gsl_integration_glfixed_table*>(GAUSS_TABLE));
}

const gsl_integration_glfixed_table* GaussTable::get() {

    return INSTANCE.GAUSS_TABLE;
}
