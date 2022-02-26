MRH_EvD_U_GetLocation_S_t
=========================
The MRH_EvD_U_GetLocation_S_t struct represents the data for a 
recieved user location event.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvUser_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u8_Result
      - If the recieved location is valid or not.
    * - f64_Latitude
      - The recieved latitude.
    * - f64_Longtitude
      - The recieved longtitude.
    * - f64_Elevation
      - The recieved elevation.
    * - f64_Facing
      - The recieved facing.
      

Remarks
-------
* The result is defined by :doc:`../../../../../../Enumerations/libmrhevdata_Directory/Version/MRH_EvBase/MRH_EvD_Base_Result`.