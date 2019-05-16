#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
struct OneNote{
	std::string FIO, nameOfStreet;
	int nOfBuilding, nOfAppartament;
	int dateOfBirthday[3];
	
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

     bool operator!=(const OneNote& r) const {
        return (*this<r)||(*this>r) ;  
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

std::vector<int> fLin(const OneNote &Note,std::vector<OneNote> &Notes){
	std::vector<int> vc; 
       	for(unsigned  i = 0; i<Notes.size();++i){
		if(Notes[i]==Note){
			vc.push_back(i);
		}

	}
	return vc;
}

std::vector<int> fBin(const OneNote &Note,std::vector<OneNote> &Notes){
	int L = 0;
	int R = Notes.size()-1;
	std::cout<<"R = "<<R;
	std::vector<int> vc;
	int m;
	while(L<R){
		m = std::floor((L+R)/2);
		if(Notes[m]<Note){
			L =m+1;
		}
		else{
			if(Notes[m]>Note){
				R=m-1;
			}
			else{
				vc.push_back( m);
				break;
			}
		}	
	}
	int k=1;
	while(Notes[m+k]==Note || Notes[m-k]==Note){
		if(Notes[m+k]==Note){
			vc.push_back(m+k);
		}

		if(Notes[m-k]==Note){
			vc.push_back(m-k);
		}

		k=k+1;
		std::cout<<k;
	}
	return vc;	
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
	std::clock_t fi = std::clock();
	std::vector<int> pek = fLin(Notes[500],Notes);
//	OneNote forS = Notes[pek.front()];	

	std::cout<<"Time of lin"<< fi - std::clock()<<'\n';
	std::cout<<"Linear searching. Searching for  "<<Notes[10]<<" found: ";
	//for(auto i :pek){
	//	std::cout<<i<<' ';
	//}
//	shakerSort(Notes);	
	std::clock_t  fi2 = std::clock();
	insertingSort(Notes);    
	//std::cout<<pek[0];
	std::cout<<"after sort"<<'\n';
	//std::vector<int> kek = fBin(Notes[pek[0]],Notes);
	std::cout<<"Time of bin + sort "<< fi2 - std::clock()<<'\n';
//	std::cout<<Notes[5]<<'\n';
	std::cout<<"Inserting sort. Log bin searcing for "<<Notes[10]<<" found: ";
//	for (std::vector<OneNote>::iterator it=Notes.begin();it<Notes.end();it++){
//                //std::cout<< *it << ' ';    
//		std::cout<< *it<< ' ' ;
//	    }

}

