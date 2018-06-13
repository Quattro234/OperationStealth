    int player::pXPGain(int mEXP){//Matthew Fretwell, updates the total XP of the player after combat.
           int xpGain = playerDB[7] + mEXP;
            playerDB[7] = xpGain;
            sqlite::sqlite db( "gamedb.db" );
            auto cur = db.get_statement();
            cur->set_sql("UPDATE PlayerStats SET EXP = ? WHERE PlayerID = ?;");
            cur->prepare();

            cur->bind( 1, xpGain );
            cur->bind( 2, playerid);

            cur->step();
            term->printTerminalText("\n\n\n\n\nXP: " + std::to_string(getEXP()));
            return playerDB[7];
}
