/****************************************************************************/
/// @file    MSAmitranTrajectories.h
/// @author  Michael Behrisch
/// @date    13.03.2014
/// @version $Id$
///
// Realises dumping the complete network state
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo-sim.org/
// Copyright (C) 2014-2014 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef MSAmitranTrajectories_h
#define MSAmitranTrajectories_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <utils/common/SUMOTime.h>


// ===========================================================================
// class declarations
// ===========================================================================
class OutputDevice;
class MSVehicleControl;
class MSEdge;
class MSBaseVehicle;
class MSLane;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class MSAmitranTrajectories
 * @brief Realises dumping the complete network state
 *
 * The class offers a static method, which writes the complete dump of
 *  the given network into the given OutputDevice.
 *
 * @todo consider error-handling on write (using IOError)
 */
class MSAmitranTrajectories {
public:
    /** @brief Writes the complete network state of the given edges into the given device
     *
     * Opens the current time step, goes through the edges and writes each using
     *  writeEdge.
     *
     * @param[in] of The output device to use
     * @param[in] vc The vehicle control which holds the vehicles to write
     * @param[in] timestep The current time step
     * @exception IOError If an error on writing occurs (!!! not yet implemented)
     */
    static void write(OutputDevice& of, const MSVehicleControl& vc,
                      const SUMOTime timestep);


private:
    /** @brief Writes the dump of the given vehicle into the given device
     *
     * @param[in] of The output device to use
     * @param[in] veh The vehicle to dump
     * @exception IOError If an error on writing occurs (!!! not yet implemented)
     */
    static void writeVehicle(OutputDevice& of, const SUMOVehicle& veh);


private:
    static std::map<std::string, int> myWrittenTypes;
    static std::map<std::string, int> myWrittenVehicles;


private:
    /// @brief Invalidated copy constructor.
    MSAmitranTrajectories(const MSAmitranTrajectories&);

    /// @brief Invalidated assignment operator.
    MSAmitranTrajectories& operator=(const MSAmitranTrajectories&);


};


#endif

/****************************************************************************/

