/**
 * ofxShortcut.h is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxShortcut.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxShortcut.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxShortcut.h; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.02
 * @version     0.1.0
 */



#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

#define DEBUG





namespace wng {
	
	class ofxShortcut{
		
	public:
		/*
		 * Constructor
		 */
		ofxShortcut();
		
		/*
		 * Methods
		 */
		void init(string file, string mainTag, string idTag, string keyTag, string descTag);
		void init(string file);
		void parseXml(string mainTag, string idTag, string keyTag, string descTag);
		void bitmapList(int x, int y);
		bool checkKey(int k, int i);
		
		
		/* openFrameworks xmlSettings addon */
		ofxXmlSettings xml;
		
		/* array to store shortcut key integer */
		vector<int> ident;
		vector<int> key;
		vector<string> description;
		
		
	};
	
};
