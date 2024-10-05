    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (g0szqdi43g)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% g0szqdi43g.Constant_Value
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% g0szqdi43g.a4jpli2hkyv.Constant_Value
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator1_Amp
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator1_Period
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator1_Duty
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator1_PhaseDelay
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator2_Amp
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator2_Period
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator2_Duty
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% g0szqdi43g.a4jpli2hkyv.PulseGenerator2_PhaseDelay
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% g0szqdi43g.a4jpli2hkyv.Saturation1_UpperSat
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% g0szqdi43g.a4jpli2hkyv.Saturation1_LowerSat
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% g0szqdi43g.a4jpli2hkyv.Constant2_Value
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% g0szqdi43g.a4jpli2hkyv.Constant1_Value
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% g0szqdi43g.a4jpli2hkyv.ManualSwitch_CurrentSetting
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (fsg2leehhck)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% fsg2leehhck.dftnil5umr
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% fsg2leehhck.gmjmu5401l
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 19200;

                    ;% fsg2leehhck.cvbe50ahwv
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 38400;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% fsg2leehhck.cyi3ybmcmi
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% fsg2leehhck.a4jpli2hkyv.b2rhrnmqo1
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% fsg2leehhck.a4jpli2hkyv.kwhglrsu51
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%

                        ;% motors_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 8;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        sigMap.sections(5) = section;
                        clear section


                        ;% flag_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 9;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        sigMap.sections(6) = section;
                        clear section



        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 6;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (kywlqvr0ypq)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% kywlqvr0ypq.ocojtfmwbb
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% kywlqvr0ypq.ddi4fb0usd
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% kywlqvr0ypq.a4jpli2hkyv.ogd4hpohgy
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% kywlqvr0ypq.a4jpli2hkyv.kch4sw3hgm
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1210960808;
    targMap.checksum1 = 2974170251;
    targMap.checksum2 = 2899444211;
    targMap.checksum3 = 916655824;

