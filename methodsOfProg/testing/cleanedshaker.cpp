#include <iostream>
#include <fstream>
#include <string>
#include <vector>
struct OneNote{
	int nOfBuilding, nOfAppartament;
	int dateOfBirthday[3];
	std::string FIO, nameOfStreet;
	
	bool operator<(const OneNote& r) const {
		if(this->FIO.compare(r.FIO)<0){
		    return true;
		}
		if(this->FIO.compare(r.FIO)==0){
		    if(this->nameOfStreet.compare(r.nameOfStreet)<0){
			return true;
		    }
		    if(this->nameOfStreet.compare(r.nameOfStreet)==0){
			if(this->nOfBuilding<r.nOfBuilding){
			    return true;
			}
			if(this->nOfBuilding==r.nOfBuilding){
			    if(this->nOfAppartament<r.nOfAppartament){
				return true;
			    }
			    if(this->nOfAppartament==r.nOfAppartament){
				if(this->dateOfBirthday[2]-r.dateOfBirthday[2]>0){
				    return true;
				}
				if(this->dateOfBirthday[2]-r.dateOfBirthday[2]==0){
				    if(this->dateOfBirthday[1]<r.dateOfBirthday[1]){
					return true;
				    }
				    if(this->dateOfBirthday[1]==r.dateOfBirthday[1]){
					if(this->dateOfBirthday[0]<r.dateOfBirthday[0]){
					    return true;
					}
					else{
					    return false;
					}

                            }

                        }

                    }
                }
            }
            
        }
    }
	bool operator>( const OneNote& r) const {
		if(this->FIO.compare(r.FIO)>0){
		    return true;
		}
		if(this->FIO.compare(r.FIO)==0){
		    if(this->nameOfStreet.compare(r.nameOfStreet)>0){
			return true;
		    }
		    if(this->nameOfStreet.compare(r.nameOfStreet)==0){
			if(this->nOfBuilding>r.nOfBuilding){
			    return true;
			}
			if(this->nOfBuilding==r.nOfBuilding){
			    if(this->nOfAppartament>r.nOfAppartament){
				return true;
			    }
			    if(this->nOfAppartament==r.nOfAppartament){
				if(this->dateOfBirthday[2]-r.dateOfBirthday[2]<0){
				    return true;
				}
				if(this->dateOfBirthday[2]-r.dateOfBirthday[2]==0){
				    if(this->dateOfBirthday[1]>r.dateOfBirthday[1]){
					return true;
				    }
				    if(this->dateOfBirthday[1]==r.dateOfBirthday[1]){
					if(this->dateOfBirthday[0]>r.dateOfBirthday[0]){
					    return true;
					}
					else{
						return false;
					}

                            }

                        }

                    }
                }
            }
            
        }
    }
    bool operator>=( const OneNote& r) const {
        return !(*this<r);
    }

    bool operator<=(const OneNote& r) const {
        return !(*this>r);
    }

     bool operator==(const OneNote& r) const {
        return !(*this<r) && !(*this>r);
    }   


};

    std::ostream& operator<<(std::ostream& os , const OneNote  &notes){
    return os<< notes.FIO<< " " << notes.nameOfStreet<< " "<<notes.nOfBuilding<< " "<<notes.nOfAppartament<< " "<< notes.dateOfBirthday[0]<<"."<<notes.dateOfBirthday[1]<<"."<<notes.dateOfBirthday[2]<< "\n";
    }

int  readFromFile(std::vector<OneNote> &onenote, const std::string st){
	std::fstream file;
        file.open(st,std::fstream::in);
	if(!(file.is_open())){
		return 1;
	}
	else{
		while(!(file.eof())){
		    char tmpIn[256];
		    OneNote tmp = OneNote();
		    file.getline(tmpIn,256,',');
		    tmp.FIO = tmpIn;
		    file.getline(tmpIn,256,',');
		    tmp.nameOfStreet = tmpIn;
		    file.getline(tmpIn,256,',');
		    tmp.nOfBuilding = atoi(tmpIn);
		    file.getline(tmpIn,256,',');
		    tmp.nOfAppartament = atoi(tmpIn);
		    file.getline(tmpIn,256,'.');
		    tmp.dateOfBirthday[0]=atoi(tmpIn);
		    file.getline(tmpIn,256,'.');
		    tmp.dateOfBirthday[1]=atoi(tmpIn);
		    file.getline(tmpIn,256);
		    tmp.dateOfBirthday[2]=atoi(tmpIn);
	            onenote.push_back(tmp);
//		    std::cout<<tmp<<std::endl;
		}

		file.close();
		
		return 0;
	}
}

void shakerSort(std::vector<OneNote> &Notes){
	for(std::size_t il = 0, ir = Notes.size()-1; il<ir;){
		for(std::size_t j = il;j<ir;j++ ){
			if(Notes[j+1]<Notes[j]){
				std::swap(Notes[j+1],Notes[j]);
			}
		}
		ir--;

		for(std::size_t j=ir;j>il;j--){
			if(Notes[j-1]>Notes[j]){
				std::swap(Notes[j-1],Notes[j]);
			}
		}
		il++;
	}	
}

void insertingSort(std::vector<OneNote> &Notes){
        for(unsigned  i = 0; i<Notes.size();++i){
            int tmp = i;
    //        std::cout<< Notes.size()<<std::endl;
            for(unsigned  j =Notes.size(); j>0;--j){
                if((j<i)and (Notes[i]<Notes[j]) ){
                    tmp = j;
            }
                
            }
            if (tmp!=i){
                    std::vector<OneNote>::iterator it = Notes.begin();
                    Notes.insert(it+tmp,Notes[i]);
                    Notes.erase(it+i+1);
                }
    
            }
 
}	


int main(){
	
	std::vector<OneNote> Notes;
	if((readFromFile(Notes,"listec.txt"))){
		return 1;
	}
//	for (std::vector<OneNote>::iterator it=Notes.begin();it<Notes.end();it++){
//	    std::cout<< *it << ' ';
//	}
//	std::cout<<typeid(Notes[0]).name()<<std::endl;
	
	shakerSort(Notes);	
//	insertingSort(Notes);    

	for (std::vector<OneNote>::iterator it=Notes.begin();it<Notes.end();it++){
                //std::cout<< *it << ' ';    
		std::cout<< *it<< ' ' ;
	    
        
	    }

}

