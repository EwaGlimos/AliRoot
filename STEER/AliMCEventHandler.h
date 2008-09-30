// -*- mode: C++ -*-
#ifndef ALIMCEVENTHANDLER_H
#define ALIMCEVENTHANDLER_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */


/* $Id$ */

//-------------------------------------------------------------------------
//                          Class AliMCEvent
// This class gives access to MC truth during the analysis.
// Monte Carlo truth is contained in the kinematics tree (produced particles) and 
// the tree of reference hits.
//      
// Origin: Andreas Morsch, CERN, andreas.morsch@cern.ch 
//-------------------------------------------------------------------------
#include "AliVEventHandler.h"
#include "AliHeader.h"
class TFile;
class TTree;
class TParticle;
class TString;
class TClonesArray;
class TDirectoryFile;

class AliMCEvent;



class AliMCEventHandler : public AliVEventHandler
{
public:
    AliMCEventHandler();
    AliMCEventHandler(const char* name, const char* title);
    virtual ~AliMCEventHandler();
    virtual void         SetOutputFileName(const char* /* fname */) {;}
    virtual const char*  GetOutputFileName() {return 0;}
    virtual void         SetInputPath(const char* fname); 
    virtual void         SetInputTree(TTree* /*tree*/) {;}
    virtual TString*     GetInputPath() const {return fPathName;}
    virtual Bool_t       Init(Option_t* opt);
    virtual Bool_t       InitIO(Option_t* opt) {return Init(opt);};
    virtual Bool_t       Init(TTree* /*tree*/, Option_t* /*opt*/) {return kTRUE;}
    virtual Bool_t       BeginEvent(Long64_t entry);
    virtual Bool_t       Notify() { return AliVEventHandler::Notify(); };
    virtual Bool_t       Notify(const char* path);
    virtual Bool_t       FinishEvent();
    virtual Bool_t       Terminate();
    virtual Bool_t       TerminateIO();
    virtual void         ResetIO();
    virtual Bool_t       GetEvent(Int_t iev);
    virtual void         SetReadTR(Bool_t flag) { fReadTR = flag; }
    //
    AliMCEvent* MCEvent() const {if (fInitOk == kTRUE) {return fMCEvent;} else {return 0;}} 
    TTree*      TreeTR()  const {return fTreeTR;}
    TTree*      TreeK()   const {return fTreeK;}
    Int_t       GetParticleAndTR(Int_t i, TParticle*& particle, TClonesArray*& trefs);
    void        DrawCheck(Int_t i, Int_t search=0);
private:
    Bool_t      OpenFile(Int_t i);
    AliMCEventHandler(const AliMCEventHandler& handler);             
    AliMCEventHandler& operator=(const AliMCEventHandler& handler);  
private:
    AliMCEvent       *fMCEvent;          //! MC Event
    TFile            *fFileE;            //! File with TreeE
    TFile            *fFileK;            //! File with TreeK
    TFile            *fFileTR;           //! File with TreeTR
    TTree            *fTreeE;            //! TreeE  (Event Headers)
    TTree            *fTreeK;            //! TreeK  (kinematics tree)
    TTree            *fTreeTR;           //! TreeTR (track references tree)
    TDirectoryFile   *fDirK;             //! Directory for Kine Tree
    TDirectoryFile   *fDirTR;            //! Directory for TR Tree
    Int_t             fNEvent;           //! Number of events
    Int_t             fEvent;            //! Current event
    TString          *fPathName;         //! Input file path 
    char             *fExtension;        //! File name extension 
    Int_t             fFileNumber;       //! Input file number
    Int_t             fEventsPerFile;    //! Number of events per file
    Bool_t            fReadTR;           // determines if TR shall be read
    Bool_t            fInitOk;           // Initialization ok
    ClassDef(AliMCEventHandler,1)  //MC Truth EventHandler class
};
#endif 

