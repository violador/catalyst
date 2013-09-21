#!/bin/bash
file=physcon.f
i=1
until [ $i = "130" ];
do
    radius=$(echo $(grep "COVRAD($i)" $file | cut -d "=" -f2))
    config=$(echo $(grep "ELCONF($i)" $file | cut -d "=" -f2))
    symbol=$(echo $(grep "ELSYM($i)" $file | cut -d "=" -f2))
    mass=$(echo $(grep "STDMATOM($i)" $file | cut -d "=" -f2))
    name="$i-name"
    c_elec=0
    v_elec=0
    echo "    case $i:"
    echo "    {"
    echo "        element_symbol            = $symbol;"
    echo "        element_name              = $name;"
    echo "        element_mass              = $mass;"
    echo "        element_core_electrons    = $c_elec;"
    echo "        element_valence_electrons = $v_elec;"
    echo "        element_config            = $config;"
    echo "        covalent_radius           = $radius;"
    echo "    }"
    echo "    break;"
    i=$(($i + 1))
done 
