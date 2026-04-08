#include "AlbumManager.hpp"

int main(){
    try
    {
        Song song("someAlbum", "someArtist", 2010, 300);

        song.printSong();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}