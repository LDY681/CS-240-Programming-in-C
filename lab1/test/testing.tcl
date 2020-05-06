#!/usr/bin/expect -f

proc myexpect { pattern } {
        expect {
                timeout {
                        puts ""
                        puts "----------------------------"
                        puts "Unexpected Output...."
                        puts ""
                        puts "Expected:"
                        puts $pattern"
                        puts "----------------------------"
                        exit -1
                }
                -exact $pattern {}
        }
}


