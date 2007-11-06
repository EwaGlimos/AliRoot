/**************************************************************************
 * This file is property of and copyright by the ALICE HLT Project        *
 * All rights reserved.                                                   *
 *                                                                        *
 * Primary Authors: Oystein Djuvsland                                     *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/
#ifndef ALIHLTPHOSDIGITMAKERCOMPONENT_H
#define ALIHLTPHOSDIGITMAKERCOMPONENT_H

#include "AliHLTPHOSProcessor.h"
//#include "AliHLTPHOSDigitMaker.h"
//#include "TTree.h"
//#include "TClonesArray.h"


class AliHLTPHOSDigitMaker;
class TTree;
class TClonesArray;
class AliHLTPHOSDigitContainerDataStruct;



class AliHLTPHOSDigitMakerComponent : public AliHLTPHOSProcessor
{
public:
  AliHLTPHOSDigitMakerComponent();
  virtual ~AliHLTPHOSDigitMakerComponent();

  const char* GetComponentID();

  void GetInputDataTypes(std::vector<AliHLTComponentDataType>& list);

  AliHLTComponentDataType GetOutputDataType();

  void GetOutputDataSize(unsigned long& constBase, double& inputMultiplier);

  int DoEvent(const AliHLTComponentEventData& evtData, const AliHLTComponentBlockData* blocks,
	      AliHLTComponentTriggerData& trigData, AliHLTUInt8_t* outputPtr, AliHLTUInt32_t& size,
	      std::vector<AliHLTComponentBlockData>& outputBlocks);
  
  AliHLTComponent* Spawn();
  
protected:
  int DoInit(int argc, const char** argv);
  virtual int Deinit(); ////////// PTH WARNING you should Define a class AliHLTPHOSModuleProcessor
  
private:
  AliHLTPHOSDigitMaker *fDigitMakerPtr; //comment
  AliHLTPHOSDigitContainerDataStruct *fDigitContainerPtr; //comment
  UInt_t fEvtCnt; //comment
  Int_t fRunNb; //comment

  static const AliHLTComponentDataType fgkInputDataTypes[];     //HLT input data type

};
#endif
 
